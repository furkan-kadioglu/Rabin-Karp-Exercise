#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>


using namespace std;

//calculates hash values for given word
long long hash_function(string word, vector<long long>& expo_cache);


long long num_posibilities(
    int index,
    vector<vector<int>>& word_index,
    vector<int>& cache,
    vector<pair<long long,int>>& words);

int alpha_size = 37;
int modulo = 1000000007;
int justificator = 96;

int main(int argc,char* argv[]){

    //mahir's message
    string text;

    //keeps words' hash values and lengths
    vector<pair<long long,int>> words;
    

    

    //keeps exponent of alpha size with modulo
    vector<long long> expo_cache;
    expo_cache.push_back(1);
    
    
    
    /*
        READ & CALCULATE PART
        reads words from file and calculates corresponding hash value
    */
    ifstream input_file(argv[1]);
    int num_of_words;
    string word;
   

    input_file >> text;
    input_file >> num_of_words;

    //keeps index of words starts
    vector<vector<int>> word_index(text.size());

    //keeps possible subsentences after the index 
    vector<int> cache(text.size(),-1);

    for(int i=0; i<num_of_words; i++)
    {
        input_file >> word;
        words.push_back(make_pair(hash_function(word,expo_cache),word.length()));
    }

    
    // 2 detection of words in text 
    for(int j=0; j<words.size(); j++)
    {
        long long temp_hash = hash_function(text.substr(0,words[j].second),expo_cache);
        long long expo = expo_cache[words[j].second-1];
        
        for(int i=0; i<=text.size()-words[j].second; i++)
        {   
            
            if(words[j].first==temp_hash)
                word_index[i].push_back(j);



            //calculates next hash belongs to next window
            if(i+words[j].second < text.size())
            {
                temp_hash -= (int(text[i])-justificator) * expo;
                temp_hash = (temp_hash * alpha_size) % modulo;
                temp_hash += (int(text[i+words[j].second])-justificator);
                
                if(temp_hash<0)
                    temp_hash += modulo;
            }
            
    
        }

    }
    

    // 3 recursively find result 
    ofstream output_file(argv[2]);
    output_file << num_posibilities(0,word_index,cache,words);
    
    
}

long long hash_function(string word, vector<long long>& expo_cache)
{
    int len_word = word.size();
    long long hash = 0;
    
    while(expo_cache.size() < len_word)
    {   
        hash = (expo_cache.back() * alpha_size) % modulo;
        expo_cache.push_back(hash);
    }
    
    hash = 0;

    for(int i=0; i<len_word; i++)
    {
        hash += (int(word[len_word-i-1])-justificator) * expo_cache[i];
    }
    return hash % modulo;
    
}

long long num_posibilities(
    int index,
    vector<vector<int>>& word_index,
    vector<int>& cache,
    vector<pair<long long,int>>& words)
{
    long long possibilities = 0;
    for(int key: word_index[index])
    {

        if(words[key].second + index < word_index.size())
        {
            if(cache[words[key].second + index] == -1)
                num_posibilities(index + words[key].second,word_index,cache,words);
                
            possibilities += cache[words[key].second + index];
        }
        else
            possibilities += 1;

            
            
        
    }
    cache[index] = possibilities % modulo;
    return possibilities % modulo;
}



