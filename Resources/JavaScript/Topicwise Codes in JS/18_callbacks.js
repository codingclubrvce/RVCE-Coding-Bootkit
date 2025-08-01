function greet(name, callback){
    const greeting = "Hello " + name
    callback(greeting)
}

function display(message){
    console.log(message)
}

greet("Samkit", display)

// Callback Hell - Pyramid of DOOM