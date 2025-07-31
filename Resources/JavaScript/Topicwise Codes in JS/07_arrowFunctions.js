//func with no argument and no return
var hello = () => console.log("Hello World")
hello()

//func with parameters and return
var sum = (a, b) => a+b
console.log(sum(4, 3))

//func with parameters and multiple lines
var process = (a, b) =>{
    console.log("Processing")
    return a*b
}
console.log(process(4, 3))

//IIFE - Immediately Invoked Function Expression
(function(){
    console.log("IIFE")
})()