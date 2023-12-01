import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, TextInput, View } from 'react-native';
import React from 'react';
// import DateTimePicker from '@react-native-community/datetimepicker';

let val;
export default function App() {
  return (
    <View style={styles.container}>
      <StatusBar style="auto" />
      <TextInput 
                  style={{fontSize:40,width: 200, height: 100,  borderWidth:3, borderColor: 'black',padding: 20}}
                  value={val}
                  inputMode='numeric'
                  keyboardType='numeric'
     />
    
      
    
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