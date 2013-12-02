<h1>NodeSixense</h1>
- <a href="https://github.com/ironman9967/NodeSixense#description">Description</a><br>
- <a href="https://github.com/ironman9967/NodeSixense#restrictions">Restrictions</a><br>
- <a href="https://github.com/ironman9967/NodeSixense#prequisites">Prequisites</a><br>
- <a href="https://github.com/ironman9967/NodeSixense#documentation">Documentation</a><br>
- --- <a href="https://github.com/ironman9967/NodeSixense#sixensegetallnewestdataasync"><code>sixenseGetAllNewestDataAsync</code></a><br>
- --- <a href="https://github.com/ironman9967/NodeSixense#sixensegetallnewestdataasyncstop"><code>sixenseGetAllNewestDataAsyncStop</code></a><br>
- --- <a href="https://github.com/ironman9967/NodeSixense#events">Events</a><br>
- <a href="https://github.com/ironman9967/NodeSixense#license">License</a><br>
<h2>Description:</h2>
A NodeJS addon/port of the Sixense SDK for "six-degrees-of-freedom" controllers, such as the Razer Hydra™.
<h2>Restrictions:</h2>
1. Linux based OS<br>
2. 64-bit processor<br>
3. Currently only one sixense base is supported.<br>
<h2>Prequisites:</h2>
1. node-gyp installed globally: <code>sudo npm install -g node-gyp</code><br>
<h2>Documentation:</h2>
Refer to the 'Sixense_SDK_Reference.pdf' and 'Sixense_SDK_Overview.pdf' available from Sixense's website for instructions on how to utilize the available SDK methods. All the Sixense SDK methods work as described.
<h3>There are a few additional methods meant to make working with the module easier in JavaScript:</h3>
<h6><code>sixenseInit()</code> and <code>sixenseSetActiveBase(0)</code> should be called before accessing any of the following mechanics. Once finished with these mechanics <code>sixenseExit()</code> should be called.</h6>
<h4><code>sixenseGetAllNewestDataAsync</code>:</h4>
An asyncronous version of <code>sixenseGetAllNewestData</code>. This method accepts a callback that should accept <code>error</code> and <code>allData</code> parameters. The callback will be called every ~16.6ms (the refresh rate of the SixenseSDK). Once this method is invoked, you must call <code>sixenseGetAllNewestDataAsyncStop</code> in order to stop the module from executing the callback sent to <code>sixenseGetAllNewestDataAsync</code>.
<h4><code>sixenseGetAllNewestDataAsyncStop</code>:</h4>
This method is used to stop the execution of the callback sent <code>sixenseGetAllNewestDataAsync</code>. If <code>sixenseGetAllNewestDataAsync</code> hasn't been called, this method doesn't do anything.
<h4>Events:</h4>
<code>node-sixense</code> is a <code>EventEmitter</code> from the Nodejs event module. All listeners must be removed before exiting your application. All event callbacks should accept a <code>data</code> (the data listened for) and <code>metaData</code> (metaData about the data provided). All object level events will be emitted every ~16.6ms. All property level events will be emitted when that property changes.<br>
Here is a list of the events that can be listened for:<br>
- <code>controller:[index]</code> - (i.e. - <code>controller:0</code>) emits all data associated with the requested controller.<br>
- <code>controller:[index]:position</code> - emits all position data associated with the requested controller.<br>
- <code>controller:[index]:position:x</code> - emits the x-axis position associated with the requested controller.<br>
- <code>controller:[index]:position:y</code> - emits the y-axis position associated with the requested controller.<br>
- <code>controller:[index]:position:z</code> - emits the z-axis position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix</code> - emits all rotationMatrix data associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:x</code> - emits all rotationMatrix x-axis data associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:x:x</code> - emits all rotationMatrix x-axis x position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:x:y</code> - emits all rotationMatrix x-axis y position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:x:z</code> - emits all rotationMatrix x-axis z position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:y</code> - emits all rotationMatrix y-axis data associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:y:x</code> - emits all rotationMatrix y-axis x position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:y:y</code> - emits all rotationMatrix y-axis y position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:y:z</code> - emits all rotationMatrix y-axis z position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:z</code> - emits all rotationMatrix z-axis data associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:z:x</code> - emits all rotationMatrix z-axis x position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:z:y</code> - emits all rotationMatrix z-axis y position associated with the requested controller.<br>
- <code>controller:[index]:rotationMatrix:z:z</code> - emits all rotationMatrix z-axis z position associated with the requested controller.<br>
- <code>controller:[index]:rotationQuaternion</code> - emits all rotationQuaternion data associated with the requested controller.<br>
- <code>controller:[index]:rotationQuaternion:x</code> - emits all rotationQuaternion x-axis associated with the requested controller.<br>
- <code>controller:[index]:rotationQuaternion:y</code> - emits all rotationQuaternion y-axis associated with the requested controller.<br>
- <code>controller:[index]:rotationQuaternion:z</code> - emits all rotationQuaternion z-axis associated with the requested controller.<br>
- <code>controller:[index]:rotationQuaternion:w</code> - emits all rotationQuaternion unit vector associated with the requested controller.<br>
- <code>controller:[index]:joystick</code> - emits all joystick data associated with the requested controller.<br>
- <code>controller:[index]:joystick:x</code> - emits joystick x-axis position associated with the requested controller.<br>
- <code>controller:[index]:joystick:y</code> - emits joystick y-axis position associated with the requested controller.<br>
- <code>controller:[index]:trigger</code> - emits all trigger state associated with the requested controller.<br>
- <code>controller:[index]:buttons</code> - emits all button data associated with the requested controller.<br>
- <code>controller:[index]:buttons:button1</code> - emits button 1 state associated with the requested controller.<br>
- <code>controller:[index]:buttons:button2</code> - emits button 2 state associated with the requested controller.<br>
- <code>controller:[index]:buttons:button3</code> - emits button 3 state associated with the requested controller.<br>
- <code>controller:[index]:buttons:button4</code> - emits button 4 state associated with the requested controller.<br>
- <code>controller:[index]:buttons:start</code> - emits start button state associated with the requested controller.<br>
- <code>controller:[index]:buttons:bumper</code> - emits bumper button state associated with the requested controller.<br>
- <code>controller:[index]:buttons:joystick</code> - emits joystick button state associated with the requested controller.<br>

<h2>License:</h2>
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
