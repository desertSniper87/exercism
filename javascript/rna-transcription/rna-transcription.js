export const complRNAStrant = {
  "G": "C",
  "C": "G",
  "T": "A",
  "A": "U"
};

export const toRna = rna => {
  let transcryptedRna = '';
  const rnaLength = rna.length;

  for ( i=0; i<rnaLength; i++ ){
    let rnaStrand = rna[i];
    transcryptedRna += complRNAStrant[rnaStrand];
  }

  return transcryptedRna;
};
