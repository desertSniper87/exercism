//
// This is only a SKELETON file for the 'Resistor Color Duo' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const COLORS = ["black","brown","red","orange","yellow","green","blue","violet","grey","white"] ;


export const decodedValue = ([color1, color2]) => {
  const code1 = COLORS.indexOf(color1);
  const code2 = COLORS.indexOf(color2);

  const resistor_val = code1 * 10 + code2;

  return resistor_val;

};
