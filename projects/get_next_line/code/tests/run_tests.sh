#!/usr/bin/env bash
# Build get_next_line + the harness in a scratch dir, sweeping BUFFER_SIZE.
# Originals are never modified; the copies are patched only for the build.

set -u

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
TESTS="$ROOT/tests"
CC="${CC:-cc}"
BASE_FLAGS="-Wall -Wextra -g"
SAN_FLAGS="${SAN_FLAGS:--fsanitize=address,undefined -fno-omit-frame-pointer}"

build_and_run() { # $1=BUFFER_SIZE  $2=sanitizer flags
	local bs="$1" san="$2" dir
	dir="$(mktemp -d)"
	cp "$ROOT/get_next_line.c" "$ROOT/get_next_line.h" \
	   "$ROOT/get_next_line_utils.c" "$dir/" 2>/dev/null

	# Drop the hard-coded BUFFER_SIZE so -D controls it.
	sed -i -E 's/^[[:space:]]*#define[[:space:]]+BUFFER_SIZE.*$//' "$dir/get_next_line.h"
	# get_next_line.c ships with its own main(); drop it for the harness.
	awk '/^[[:space:]]*int[[:space:]]+main[[:space:]]*\(/{exit} {print}' \
		"$dir/get_next_line.c" > "$dir/gnl.c"

	# shellcheck disable=SC2086
	if ! $CC $BASE_FLAGS $san -DBUFFER_SIZE="$bs" -I"$dir" \
		"$dir/gnl.c" "$dir/get_next_line_utils.c" "$TESTS/test_gnl.c" \
		-o "$dir/test_gnl"; then
		echo ">>> COMPILE FAILED (BUFFER_SIZE=$bs)"
		rm -rf "$dir"
		return 1
	fi

	ASAN_OPTIONS="detect_leaks=${DETECT_LEAKS:-0}:abort_on_error=0" \
		"$dir/test_gnl"
	local rc=$?
	if [ "$rc" -ge 128 ] 2>/dev/null; then
		echo ">>> process ended abnormally (exit $rc; 139=SEGV, 134=abort)"
	fi
	rm -rf "$dir"
	return 0
}

echo "############################################################"
echo "# pass 1: functional sweep (no sanitizers)"
echo "############################################################"
for bs in ${BUFFER_SIZES:-1 2 3 42 1024}; do
	echo
	echo "===================== BUFFER_SIZE=$bs ====================="
	build_and_run "$bs" ""
done

if [ "${SKIP_SAN:-0}" != "1" ]; then
	echo
	echo "############################################################"
	echo "# pass 2: AddressSanitizer / UBSan (BUFFER_SIZE=${SAN_BS:-42})"
	echo "############################################################"
	build_and_run "${SAN_BS:-42}" "$SAN_FLAGS"
fi
