import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, TextInput, View, Alert, Button } from 'react-native';
import React, { useState } from 'react';
import { sendItToEsp } from './SendIT.js';

export default function App() {

  const [Hour, setHour] = useState("");
  const [Minutes, setMinutes] = useState("");
  const clearHour = React.useCallback(() => setHour(''), []);
  const clearMinutes = React.useCallback(() => setMinutes(''), []);

  return (
    <View style={styles.container}>
      <View style={styles.HourContainer}>
        <StatusBar style="auto" />
        <TextInput
          ref={input => { this.textInputHours = input }}
          style={styles.timeInput}
          inputMode='numeric'
          keyboardType='numeric'
          maxLength={2}
          textAlign={'center'}
          onChangeText={text => {
            if (text > 24 || text < 0) {
              Alert.alert('Godzina', 'Wartość jest z poza zakresu', [
                {
                  text: 'OK', onPress: () => {
                    clearHour();
                    this.textInputHours.clear();
                  }
                },
              ]);
            } else {
              setHour(text)
              okInput = true;
            }
          }
          }
        />
        <Text style={styles.text}> : </Text>
        <TextInput
          ref={input => { this.textInputMinutes = input }}
          style={styles.timeInput}
          inputMode='numeric'
          keyboardType='numeric'
          maxLength={2}
          textAlign={'center'}
          onChangeText={text => {
            if (text > 59 || text < 0) {
              Alert.alert('Minuta', 'Wartość jest z poza zakresu', [
                {
                  text: 'OK', onPress: () => {
                    clearMinutes();
                    this.textInputMinutes.clear();
                  }
                },
              ]);
            } else {
              setMinutes(text)
              okInput = true;
            }
          }}
        />
      </View>
      <View style={styles.container}>
        <Button
          onPress={() => sendItToEsp("asdf",Hour,Minutes)}
          title="Send it"
          color={'#000000'}
        />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#1c1c1c',
  },
  HourContainer: {
    flex: 1,
    flexDirection: 'row',
    backgroundColor: '#1c1c1c',
    color: '#eeeeda',
    alignItems: 'center',
    justifyContent: 'center',
  },
  timeInput: {
    fontSize: 50,
    width: 100,
    height: 100,
    borderWidth: 3,
    borderColor: 'white',
    color: '#daeeee',
    borderRadius: 50
  },
  text: {
    color: '#daeeee',
    fontSize: 50,
  },
 
});
