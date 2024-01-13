const showToastWithGravity = (e) => {
  ToastAndroid.showWithGravity(
    e,
    ToastAndroid.SHORT,
    ToastAndroid.CENTER,
  );
};
export function sendItToEsp(url, hour, minutes) {
  console.log(url, hour, minutes);
  url = "http://" + url + "/?hour=" + hour + "&minutes=" + minutes;
 
 try{
  fetch(url, {
    method: 'GET'
  }).then((response) => response.text())
    .then((data) => {
      if (data == "ok") {
        console.log("ok");
      }
    }).catch((e)=>{
      showToastWithGravity(e);
// it just does not work and still returns unhandled promise rejection 
    });
  }catch(e){
    
    showToastWithGravity(e);
    console.log(e);
  }
}