 import firebase from "firebase";
 // add your firebase credentials here , ThankYou
 var firebaseConfig = {

  };

  const app = firebase.initializeApp(firebaseConfig);
  const db = firebase.firestore()
  const rtdb = firebase.database()
  const timestamp = firebase.firestore.FieldValue.serverTimestamp();
  export {db , app ,timestamp ,rtdb}