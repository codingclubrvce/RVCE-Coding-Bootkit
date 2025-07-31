/**
 * Promise from Simran
*/

const simranPromise = new Promise((resolve, reject) => { //create a new promise object  

    let parentDecision = true

    if(parentDecision){
        resolve({message: "Yayy, shaadi ki taiyaari karo, papa maan gaye", parentDecision})
    }
    else{
        reject({message: "IAS mil gaya papa ko, sorry", parentDecision})
    }

}); 

//Action on the promise

simranPromise.then(({message, parentDecision})=>{ //resolve / positive
    console.log("Simran message : ", message)
    console.log("Parent decision : ", parentDecision)
    console.log("Book the wedding venue")
}).catch(({message, parentDecision}) => { //reject / negative
    console.log("Simran message : ", message)
    console.log("Parent decision : ", parentDecision)
    console.log("Tinder, kaha ho yaar")
})