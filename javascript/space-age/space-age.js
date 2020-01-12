const orbitalPeriodInDays = {
  "mercury": 87.97,
  "venus" : 224.70, 
  "earth": 365.26,
  "mars": 686.98,
  "jupiter": 4332.82,
  "saturn": 10755.70,
  "uranus": 30687.15,
  "neptune": 60190.03  
}
export const age = (planet, seconds) => {
  let ageInDays =  seconds / 60 / 60 / 24;
  let ageInOtherPlanet = ageInDays / orbitalPeriodInDays[planet];
  return Math.round(ageInOtherPlanet * 100) / 100
};
