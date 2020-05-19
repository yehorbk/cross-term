# Cross-Term
This terminal emulator allows users to configure and overload their commands.
# How to Use
All settings are in file settings.xml. This file have a basic structure and consists of `greeting`, `prompt` and `commands` sections. You able to use any commands or run files with scripts. 
# Examples of Configuration
## Simple Unix Terminal
settings.xml:
```
...
<greeting>date</greeting>
<prompt>printf "$USER:${PWD##*/}$ "</prompt>
...
```
Result:
```
Tue May 19 20:55:49 EEST 2020
admin:Desktop$  
```
## Git Publisher
publish.sh:
```
git add . ;
git commit ;
git push
```
settings.xml:
```
<Item>
  <command>publish</command>
  <execute>./publish.sh</execute>
</Item>
```
# Build
- [Unix](https://github.com/yehorbk/cross-term/blob/master/docs/building-unix.md)
- [Windows](https://github.com/yehorbk/cross-term/blob/master/docs/building-windows.md)
# Third Party
- [pugixml](https://pugixml.org)
- [trim](https://stackoverflow.com/a/25385766/11804288)
# Author
**Yehor Bublyk**: [GitHub](https://github.com/yehorbk) • [Twitter](https://twitter.com/thisisyehorbk)
