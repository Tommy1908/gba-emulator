#!/usr/bin/env bash

set -e

if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <ruta_al_archivo>"
    exit 1
fi

FILE="$1"

PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$PROJECT_DIR"

cd build
make

cd ..

./build/platform/desktop/gbaemu "$FILE"

