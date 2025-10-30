template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int probes = 0;
    int index = this->hash1(key);
    for(int i = 0; i < this->M; i++){
        probes++;
        int newIndex = this->probeIndex(key, i);
        if(!this->occupied[newIndex]){ 
            this->table[newIndex] = key; // insert the key
            this->occupied[newIndex] = true; // occupied
            this->N++;
            return probes;
        }
    }
    return 0;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    int probes = 0;
    int index = this->hash1(key);
    for(int i = 0; i < this->M; i++){
        probes++;
        int newIndex = this->probeIndex(key, i);

        if(!this->occupied[newIndex]){
            return {false, probes}; // checks for empty slot
        }
        if(this->table[newIndex] == key){
            return{true, probes}; // key is found
        }
    }

    return {false, probes}; // key is not found overall
}
