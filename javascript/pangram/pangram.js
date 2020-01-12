const alphaRe = /[a-z]/g;

export const isPangram = sentence => {
  let matched_elements = sentence.toLowerCase()
                                 .match(alphaRe);
  let unique_matched_elements = [...new Set(matched_elements)];
  if (unique_matched_elements.length === 26) {
    return true;
  } else {
    return false;
  }
};
