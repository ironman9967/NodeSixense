NodeSixense
===========

**Description:**<br>
A NodeJS addon/port of the Sixense SDK for "six-degress-of-freedom" controllers, such as the Razer Hydra. Currently, Windows is not supported and a 64-bit machine is required.

**Prequisites:**<br>
1. node-gyp installed globally: 'sudo npm install -g node-gyp'<br>
2. The 'sixense.h' file needs to by copied into the './SixenseSDK' folder. Under Sixense's license, I cannot provide this file for you.

**Build Instructions:**<br>
From the directory of the project, execute 'sudo node-gyp rebuild'.

**Documentation:**<br>
Refer to the 'Sixense_SDK_Reference.pdf' and 'Sixense_SDK_Overview.pdf' available from Sixense's website for instructions on how to uilize the available methods.

**License:**<br>
The Sixense SDK is licensed under Sixense EULA which can be found here: http://sixense.com/eula

The JS port and Nodejs addon portions are licensed under:

The MIT License (MIT)

Copyright (c) 2013 Tyson Hester

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
