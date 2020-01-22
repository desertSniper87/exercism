export const hey = (message) => {
  if (isQuestion(message)) {
    if (isRude(message))
      return "Calm down, I know what I\'m doing!";
    else
      return 'Sure.';
  }
  else if (isAlphanumeric(message)) {
    if (isRude(message))
      return 'Whoa, chill out!';
    else 
      return 'Whatever.';
  }
  else 
    return 'Fine. Be that way!';
};

const isAlphanumeric = msg => {
  return msg.match(/[a-zA-Z0-9?]+/)
};

const isQuestion = msg => {
  return msg.trim().slice(-1) === '?';
}

const isRude = msg => {
  return msg.match(/[A-Z]/) && msg.toUpperCase() === msg;
}


