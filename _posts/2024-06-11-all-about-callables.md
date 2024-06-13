---
layout: post
title: "All About Calls"
toc: true
---

This is a terse but detailed description of [function objects in C++](https://en.cppreference.com/w/cpp/utility/functional) (any object for which the function call operator `operator()` is defined), including the different ways to pass them to functions and how each are implemented under the hood.

## The Callables

The three main types of function objects are [lambdas](https://en.cppreference.com/w/cpp/language/lambda) (anonymous function objects), [`std::function`](https://en.cppreference.com/w/cpp/utility/functional/function), and C-style function pointers.

### Function Pointers

Exactly what they sound like: just a pointer to the address of a function. Note that `&foo` and `foo` are equivalent.

<iframe width="800px" height="200px" src="https://godbolt.org/e?hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:32,endLineNumber:10,positionColumn:32,positionLineNumber:10,selectionStartColumn:32,selectionStartLineNumber:10,startColumn:32,startLineNumber:10),source:'int+foo(int+x)+%7B+return+x%3B+%7D%0A%0Aauto+callFunctionPointer(auto+functionPointer)%0A%7B%0A++++return+functionPointer(5)%3B%0A%7D%0A%0Aint+main()%0A%7B%0A++++return+callFunctionPointer(foo)%3B%0A%7D'),l:'5',n:'1',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g141,filters:(b:'0',binary:'1',binaryObject:'1',commentOnly:'0',debugCalls:'1',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'0',trim:'1',verboseDemangling:'0'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'-std%3Dc%2B%2B20',overrides:!(),selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1),l:'5',n:'0',o:'+x86-64+gcc+14.1+(Editor+%231)',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

### Lambdas

Lambdas are NOT `std::function`s. 