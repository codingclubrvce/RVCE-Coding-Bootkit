async function getMessage(){
    return "Hello World"
}
//on adding async infront of the function, it will now return Promise Objects

console.log(getMessage()) //Promise { 'Hello World' }

getMessage().then(result => {
    console.log(result) //Hello World
})

/**
 * Print hello after a wait
 */

/*
function printAfterWait(){
    console.log("First Line")
    setTimeout(()=>{
        console.log("Middle Line")
    }, 3000)
    console.log("Last Line")
}
*/

//printAfterWait()
/**
 * First Line
 * Last Line
 * 1s 2s 3s Middle Line
 */

console.log("Line before function definition")
async function printAfterWait(){
    console.log("First Line")
    
    let data = new Promise((resolve, reject) => {
        setTimeout(()=>{
            resolve("Middle Line")
        }, 3000)
    })

    let result = await data //start waiting for data promise to complete
    console.log(result)
    
    console.log("Last Line")
}

printAfterWait()
console.log("Line after function call")

/**
 * Line before function definition
 * First Line
 * Line after function call
 * 1s 2s 3s Middle Line
 * Last Line
 */