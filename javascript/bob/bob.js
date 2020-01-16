export const hey = (message) => {
  if (message.match(/[a-zA-Z0-9?]+/)){
    if (message.trim().slice(-1) === '?')
      return (message.includes("HELL") ? "Calm down, I know what I\'m doing!" : 'Sure.');
    else if (message.match(/[A-Z]/) && message.toUpperCase() === message)
      return 'Whoa, chill out!';
    else 
      return 'Whatever.';
  } else 
    return 'Fine. Be that way!';
};
