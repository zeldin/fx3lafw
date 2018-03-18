#!/bin/sh

set -e

if [ "$#" -ne 1 ]; then
  echo >&2 "Usage: $0 EZ-USB_FX3_TRM.pdf"
  exit 1
fi

if [ -f "$1" -a -r "$1" ]; then
  :
else
  echo >&2 "$1 is not a readable file"
  exit 1
fi

pdftohtml -s -i -xml -c "$1" trm.xml
python3 `dirname $0`/convert.py
rm trm.xml
