export const hey = (message) => {
  if (message.slice(-1) === '?')
    return 'Sure.';
  if (message.toUpperCase() === message)
    return 'Whoa, chill out!';
  else 
    return 'Whatever.';
};
