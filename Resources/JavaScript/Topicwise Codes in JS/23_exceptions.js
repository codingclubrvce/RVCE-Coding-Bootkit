//console.log("Hello 
//  SyntaxError: Invalid or unexpected token

/**let x = 5
console.log(x.toUpperCase())*/
//  TypeError: x.toUpperCase is not a function

/**let num = 5;
for(i=-3; i<5; i++){
    console.log(num/i)
}*/
/* Logical Error
-1.6666666666666667
-2.5
-5
Infinity
5
2.5
1.6666666666666667
1.25
*/
try{
    let obj = {
        name : "samkit"
    }
    console.log(obj.name)
}catch(err){
    console.log("Exception Handled")
}
finally{
    console.log("I am always executed")
}
/*
    samkit
    I am always executed
*/

try{
    let obj = undefined
    console.log(obj.name)
}catch(err){
    console.log("Exception Handled")
    console.log(err)
}
finally{
    console.log("I am always executed")
}
/*
    Exception Handled
TypeError: Cannot read properties of undefined (reading 'name')
    at Object.<anonymous> (d:\Web Development\JAVASCRIPT\23_exceptions.js:33:21)
    at Module._compile (node:internal/modules/cjs/loader:1376:14)
    at Module._extensions..js (node:internal/modules/cjs/loader:1435:10)
    at Module.load (node:internal/modules/cjs/loader:1207:32)
    at Module._load (node:internal/modules/cjs/loader:1023:12)
    at Function.executeUserEntryPoint [as runMain] (node:internal/modules/run_main:135:12)
    at node:internal/main/run_main_module:28:49
    I am always executed
*/


