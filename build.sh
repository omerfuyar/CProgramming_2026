#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
tasks_dir="$script_dir/tasks"
build_dir="$script_dir/build"

mkdir -p "$build_dir"

shopt -s nullglob
sources=("$tasks_dir"/*.c)

if ((${#sources[@]} == 0)); then
    printf 'No C files found in %s\n' "$tasks_dir" >&2
    exit 1
fi

for source in "${sources[@]}"; do
    if [[ ! -s "$source" ]]; then
        printf 'Skipping empty source: %s\n' "$source" >&2
        continue
    fi

    name="$(basename "${source%.c}")"
    output="$build_dir/$name.ignore"

    printf 'Building %s -> %s\n' "$source" "$output"
    gcc -Wall -Wextra -std=c11 "$source" -o "$output"
done
