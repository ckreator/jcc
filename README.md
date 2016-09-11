# JCC - Use JavaScript Features in C:

JCC enables you to use common JavaScript features in your C programs.
There are several reasons why I chose JS for OOP features in C:

1. JS Prototypes are fairly easy to implement and yet very powerful and
       flexible
2. JS has closures
3. JS has first-class Functions (which is insanely useful in metaprogramming, especially in combination with closures)
4. JS provides automatic Garbage Collection (although many languages do)
5. I just love JS and as a professional JS Developer, it would be stupid not to use JS ;)

#### Note: The current JS-Standard I'm aiming for is ECMAScript 5
JCC does NOT provide a JS-type runtime, it's a tool to use all JS's Goods in
your C programs


## Features:
The API Provides the following features:

- Using Objects, Prototypes and Inheritance
- Use closures and functions as first-class objects
- All the memory-related API functions provide seamless 'garbage collection'

Dependencies:
    * [ckreMM](https://github.com/ckreator/ckreMM) (or any other memory pooling system)




           __     ______
          / /____/ ____/
     __  / / ___/ /     
    / /_/ / /__/ /___   
    \____/\___/\____/   


MIT License

Copyright (c) 2016 Yuriy Kristian Voshchepynets

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
