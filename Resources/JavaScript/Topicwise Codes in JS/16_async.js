console.log("Hello from first line")

setTimeout(() => {
    console.log("Hello from callback function - 2 second")
}, 2000)

setTimeout(() => {
    console.log("Hello from callback function - 3 second")
}, 3000)

console.log("Hello from last line")

/**
 * Hello from first line
 * Hello from last line
 * Hello from callback function
 */