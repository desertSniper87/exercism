#!/usr/bin/env bash

main () {
    if [ $# -eq 1 ]; then
        name=$1
        echo "Hello, $name"
    else
        echo "Usage: ./error_handling <greetee>"
    fi
}

main "$@"

