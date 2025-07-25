
const randomNum = () => {
  let random = 1 + Math.floor(Math.random() * 7);
  return random * 1000;
}

function hacked() {
  return new Promise((resolve, reject) => {

    setTimeout(() => {
      resolve(200);
    }, randomNum())
  })
}

let addItem = async (text) => {
  await hacked();
  let div = document.createElement("div");
  div.innerText = text;
  document.body.append(div);
}

async function main() {
  let t = setInterval(() => {

    let element = document.body.getElementsByTagName("div");
    element = element[element.length - 1]
    if (element.innerText.endsWith("...")) {
      element.innerHTML = element.innerHTML.slice(0, element.innerHTML.length - 3);
    } else {
      element.innerHTML += '.';
    }

  }, 100);

  let display = ["Hacking Dilraj User4232", "Username found DILLU", "Connecting to facebook"];

  for (let text of display) {
    await addItem(text);
  }
}
main()






// div.innerText = text;
// let element = document.body.lastElementChild;
// if (element.innerText.endsWith("...")) {
//   element.innerText = element.innerText.slice(0, element.innerText.length - 3);
// } else {
//   element.innerText += '.';
// }