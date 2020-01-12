const oneGigaSecond = 1000000000 * 1000; //miliseconds

export const gigasecond = date => {
  let seconds = date.getTime() + oneGigaSecond;
  return new Date(seconds);
};
