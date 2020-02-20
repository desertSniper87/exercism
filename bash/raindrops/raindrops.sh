#!/usr/bin/env bash

function main {
    echo "Hello World"
    echo "$1"
    echo "$(factor $1)"
}

main "$@"
