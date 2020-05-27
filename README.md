# Cross-Term
[![Build Status](https://travis-ci.org/yehorbk/cross-term.svg?branch=master)](https://travis-ci.org/yehorbk/cross-term)
[![npm version](https://img.shields.io/github/v/release/yehorbk/cross-term)](https://www.npmjs.com/package/impress)
[![Licence](https://img.shields.io/github/license/yehorbk/cross-term)]()
# How to use
All settings are in file settings.xml. This file have a basic structure and consists of `greeting`, `prompt` and `commands` sections. You able to use any commands or run files with scripts.
## Settings XML Basic Structure
```
<?xml version="1.0"?>
<settings>
  <greeting><!-- TODO --></greeting>
  <prompt><!-- TODO --></prompt>
</settings>
<commands>
  <Item>
    <command><!-- TODO --></command>
    <execute><!-- TODO --></execute>
  </Item>
</commands>
```
## Settings Description
- `greeting` - terminal greeting
- `prompt` - common terminal prompt
- `commands` - list of commands
- `command` - what word will be used to execute script
- `execute` - script or file what will be executed
# Examples of Configuration
## Simple Unix Terminal
```
<!-- settings.xml -->
...
<greeting>date</greeting>
<prompt>printf "$USER:${PWD##*/}$ "</prompt>
...
```
```
# result
Tue May 19 20:55:49 EEST 2020
admin:Desktop$  
```
## Git Publisher
```
# publish.sh
git add . ;
git commit ;
git push
```
```
<!-- settings.xml: -->
...
<Item>
  <command>publish</command>
  <execute>./publish.sh</execute>
</Item>
...
```
# Build
- [Unix](https://github.com/yehorbk/cross-term/blob/master/docs/building-unix.md)
- [Windows](https://github.com/yehorbk/cross-term/blob/master/docs/building-windows.md)
# Third Party and Libs
- [pugixml](https://pugixml.org)
- [trim](https://stackoverflow.com/a/25385766/11804288)
# Requirements
- `gcc` and `g++` compilers
- `c++11` or above C++ versions
# Author
**Yehor Bublyk**: [GitHub](https://github.com/yehorbk) • [Twitter](https://twitter.com/thisisyehorbk)
