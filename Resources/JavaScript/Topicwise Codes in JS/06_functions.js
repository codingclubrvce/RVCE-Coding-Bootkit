function hello(){
    console.log("Hello World")
}

hello() //function calling

function sum(a, b=0){
    return a + b
}
var a = sum(3, 4)
console.log(a)

function func(){
    console.log(arguments)
}
func(1, 2, 3, 4, 5, 6, 7)