import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, TextInput, View } from 'react-native';
import React from 'react';
let val;
export default function App() {
  const [val, onChangeText] = React.useState('Useless Multiline Placeholder');
  return (
    <View style={styles.container}>
      <Text style={{color: 'blue'}}>This is my text lol</Text>
      <StatusBar style="auto" />
      <TextInput 
                  style={{width: 200, height: 100,  borderWidth:3, borderColor: 'black',}}
                  value={val}
                  onChangeText = {val => onChangeText(val)} />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: val,
    alignItems: 'center',
    justifyContent: 'center',
  },
  text:{
    color: 'black'
  }
});
// import React from 'react';
// import {View, TextInput} from 'react-native';

// const MultilineTextInputExample = () => {
//   const [value, onChangeText] = React.useState('Useless Multiline Placeholder');

//   // If you type something in the text box that is a color, the background will change to that
//   // color.
//   return (
//     <View
//       style={{
//         backgroundColor: value,
//         borderBottomColor: '#000000',
//         borderBottomWidth: 1,
//       }}>
//       <TextInput
//         editable
//         multiline
//         numberOfLines={4}
//         maxLength={40}
//         onChangeText={text => onChangeText(text)}
//         value={value}
//         style={{padding: 10, backgroundColor: 'gray'}}
//       />
//     </View>
//   );
// };

// export default MultilineTextInputExample;