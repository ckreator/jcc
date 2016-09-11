# JCC - Use JavaScript Features in C

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
