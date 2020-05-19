# Building cross-term for Windows
You can use different methods to build project, but I recommend you to use `make` or it analogs and Visual Studio (easier).
- To build with `make` you should to reconfigure `Makefile` to match Windows standarts and then:
```
$ git clone https://github.com/yehorbk/cross-term.git
$ cd cross-term/cross-term
$ make
```
- To build with Visual Studio you need to create the C++ Console Application and move files from `cross-term/cross-term/src` to
your project's source folder and run 'Build'. 

\***version 1.0.0 doesn't work on Windows yet**
