export function sendItToEsp(url, hour, minutes) {
  console.log(url, hour, minutes);
  url = "http://" + url + "/?hour=" + hour + "&minutes=" + minutes;
  fetch(url, {
    method: 'GET'
  }).then((response) => response.text())
    .then((data) => {
      if (data == "ok") {
        console.log("ok");
      }
    });
}