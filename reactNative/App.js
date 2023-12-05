import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, TextInput, View } from 'react-native';
import React, { useState } from 'react';

let val;
export default function App() {
  
  const [myText, setMyText] = useState("My Original Text");
  return (
    <View style={styles.container}>
      <StatusBar style="auto" />
      <TextInput 
                  style={styles.timeInput}
                  inputMode='numeric'
                  keyboardType='numeric'
                  maxLength={2}                
                  onChangeText={text => setMyText(text)}
     />
                    <Text>
                            {myText}{" "}:{" "}
                    </Text>
                    
    
     <TextInput 
                  style={styles.timeInput}
                  value={val}
                  inputMode='numeric'
                  keyboardType='numeric'
                  maxLength={2}
      />
          
    
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'row',
    backgroundColor: val,
    alignItems: 'center',
    justifyContent: 'center',
  },
  timeInput: {
    fontSize:40,
    width: 100,
    height: 100,
    borderWidth:3,
    borderColor: 'black',
    padding: 20,
  },
  text:{
    color: 'black',
    fontSize: 50,
  }
});
