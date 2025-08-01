/**
 * var
 * - it is used to define a variable
 * - function scope but no block scope
 * - it is hoisted
 */
function f1(){
    var i = 5
    // console.log(i)
}
f1()
// console.log(i)
{
    var j = 7
}
console.log(j) //block scope

//hoisting
console.log(a)  //undefined
var a = 23
console.log(a) //23

/**
 * let
 * - no hoisting support
 * - function scope and block scope
 */
console.log(b) //error - no hoisting
let b = 7
{
    let c = 1
}
console.log(c) //c is not defined (due to block scope)

/**
 * const
 * - scope is exactly same as let
 * - const variables cannot be reassigned values
 */
const country = "India"
country = "USA" //error