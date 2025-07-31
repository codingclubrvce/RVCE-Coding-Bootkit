// function hello(){
//     let name= "Samkit"
//     console.log(name)
// }

// hello()

// console.log(name)

// used in encapsulation when you are able to store the data but you don't show it to anyone

function outerFn(){
    let outerVar = "I am from the outer func"
    function innerFn(){
        console.log(outerVar)
    }
    return innerFn  
}

let fn = outerFn()
fn()