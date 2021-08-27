#!/bin/bash

find "$PREFIX" -type f ! -iname ".*" ! -path "${PREFIX}/.extensions/*" | sed "s,^${PREFIX}/,,;s/.gpg$//" | sort
