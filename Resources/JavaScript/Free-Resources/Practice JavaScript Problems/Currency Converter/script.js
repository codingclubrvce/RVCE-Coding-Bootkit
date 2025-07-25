const base_url = "https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/usd.min.json"
const dropdowns = document.querySelectorAll(".dropdown select");
const btn = document.querySelector("form button")
const fromCurr = document.querySelector(".from select")
const toCurr = document.querySelector(".to select")
const msg = document.querySelector(".msg");

for (let select of dropdowns) {
  for (currCode in countryList) {
    let newOption = document.createElement("option");
    newOption.innerHTML = currCode;
    newOption.value = currCode;
    if (select.name === "from" && currCode === "USD") {
      newOption.selected = "selected";
    }
    else if (select.name === "to" && currCode === "INR") {
      newOption.selected = "selected";
    }
    select.append(newOption);
  }

  select.addEventListener("change", (evt) => {
    updateFlag(evt.target);
  })
}

const updateExchangeRate = async () => {
  let amount = document.querySelector(".amount input")
  let amtVal = amount.value;
  if (amtVal === "" || amtVal < 0) {
    amtVal = 1;
    amount.value = "1";
  }
  // console.log(fromCurr.value, toCurr.value);
  // const url = base_url;
  const response = await fetch(base_url);
  let data = await response.json();
  let rateTo = data["usd"][toCurr.value.toLowerCase()]
  let rateFrom = data["usd"][fromCurr.value.toLowerCase()]
  rate = rateTo / rateFrom;
  let finalAmount = rate * amtVal;
  msg.innerText = `${amtVal} ${fromCurr.value} = ${finalAmount} ${toCurr.value}`
}

const updateFlag = (element) => {
  let currCode = element.value;
  let countryCode = countryList[currCode];
  let newSrc = `https://flagsapi.com/${countryCode}/flat/64.png`;
  let img = element.parentElement.querySelector("img");
  img.src = newSrc;
}

btn.addEventListener("click", (evt) => {
  evt.preventDefault();
  updateExchangeRate();
})

window.addEventListener("load", () => {
  updateExchangeRate();
})

