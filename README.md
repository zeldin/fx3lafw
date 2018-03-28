fx3lafw
=======

This is an open source firmware for using a Cypress FX3 USB controller
as a logic analyzer with sigrok.  It does not rely on any libraries or
tools provided by Cypress under license.

This is a work in progress, it is not yet functional as a logic
analyzer.

Currently supported hardware is the CYUSB3KIT-003 "SuperSpeed Explorer
Kit".


Building
--------

On Gentoo, use `crossdev -t arm-none-eabi` to build toolchain and
newlib.

The firmware image can then be built using `make`.


License
-------

Copyright (c) 2018 Marcus Comstedt

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
