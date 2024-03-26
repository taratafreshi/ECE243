#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

volatile int* ps2_ptr = (int*) 0xFF200100; // Pointer to PS2
volatile int* pushButtons = (int *)0xFF200050; // Address for pushbutton keys

const char *englishwords[] = { "AB", "abandoned", "aberdeen", "abilities", "ability", "able", "aboriginal", "about", "above", "abraham", "abroad", "absence", "absent", "absolute", "absolutely", "absorption", "abstract", "abstracts", "abuse", "academic", "academics", "academy", "accent", "accept", "acceptable", "acceptance", "accepted", "accepting", "accepts", "access", "accessed", "accessibility", "accessible", "accessing", "accessories", "accessory", "accident", "accidents", "accommodate", "accommodation", "accommodations", "accompanied", "accompanying", "accomplish", "accomplished", "accordance", "according", "accordingly", "account", "accountability", "accounting", "accounts", "accreditation", "accredited", "accuracy", "accurate", "accurately", "accused", "acdbentity", "ace", "acer", "achieve", "achieved", "achievement", "achievements", "achieving", "acid", "acids", "acknowledge", "acknowledged", "acne", "acoustic", "acquire", "acquired", "acquisition", "acquisitions", "acre", "acres", "acrobat", "across", "acrylic", "act", "acting", "action", "actions", "activated", "activation", "active", "actively", "activists", "activities", "activity", "actor", "actors", "actress", "acts", "actual", "actually", "acute", "adaptation", "adapted", "adapter", "adapters", "adaptive", "adaptor", "add", "added", "addiction", "adding", "addition", "additional", "additionally", "additions", "address", "addressed", "addresses", "addressing", "adds", "adequate", "adidas", "adipex", "adjacent", "adjust", "adjustable", "adjusted", "adjustment", "adjustments", "admin", "administered", "administration", "administrative", "administrator", "administrators", "admission", "admissions", "admit", "admitted", "adobe", "adolescent", "adopt", "adopted", "adoption", "adrian", "adult", "adults", "advance", "advanced", "advancement", "advances", "advantage", "advantages", "adventure", "adventures", "adverse", "advert", "advertise", "advertisement", "advertisements", "advertiser", "advertisers", "advertising", "advice", "advise", "advised", "advisor", "advisors", "advisory", "advocacy", "advocate", "aerial", "aerospace", "affair", "affairs", "affect", "affected", "affecting", "affects", "affiliate", "affiliated", "affiliates", "affiliation", "afford", "affordable", "afghanistan", "afraid", "africa", "african", "after", "afternoon", "afterwards", "again", "against", "age", "aged", "agencies", "agency", "agenda", "agent", "agents", "ages", "aggregate", "aggressive", "aging", "ago", "agree", "agreed", "agreement", "agreements", "agrees", "agricultural", "agriculture", "ahead", "aid", "aids", "aim", "aimed", "aims", "air", "aircraft", "airfare", "airline", "airlines", "airplane", "airport", "airports", "alabama", "alan", "alarm", "alaska", "albania", "albany", "albert", "alberta", "album", "albums", "albuquerque", "alcohol", "alert", "alerts", "alex", "alexander", "alexandria", "alfred", "algebra", "algeria", "algorithm", "algorithms", "alias", "alice", "alien", "align", "alignment", "alike", "alive", "all", "allah", "allan", "alleged", "allen", "allergy", "alliance", "allied", "allocated", "allocation", "allow", "allowance", "allowed", "allowing", "allows", "alloy", "almost", "alone", "along", "alot", "alpha", "alphabetical", "alpine", "already", "also", "alt", "alter", "altered", "alternate", "alternative", "alternatively", "alternatives", "although", "alto", "aluminium", "aluminum", "alumni", "always", "amanda", "amateur", "amazing", "amazon", "amazoncom", "amazoncouk", "ambassador", "amber", "ambien", "ambient", "amend", "amended", "amendment", "amendments", "amenities", "america", "american", "americans", "americas", "amino", "among", "amongst", "amount", "amounts", "amp", "ampland", "amplifier", "amsterdam", "amy", "ana", "anaheim", "anal", "analog", "analyses", "analysis", "analyst", "analysts", "analytical", "analyze", "analyzed", "anatomy", "anchor", "ancient", "and", "andale", "anderson", "andorra", "andrea", "andreas", "andrew", "andrews", "andy", "angel", "angela", "angeles", "angels", "anger", "angle", "angola", "angry", "animal", "animals", "animated", "animation", "anime", "ann", "anna", "anne", "annex", "annie", "anniversary", "annotated", "annotation", "announce", "announced", "announcement", "announcements", "announces", "annoying", "annual", "annually", "anonymous", "another", "answer", "answered", "answering", "answers", "ant", "antarctica", "antenna", "anthony", "anthropology", "anti", "antibodies", "antibody", "anticipated", "antigua", "antique", "antiques", "antivirus", "antonio", "anxiety", "any", "anybody", "anymore", "anyone", "anything", "anytime", "anyway", "anywhere", "apache", "apart", "apartment", "apartments", "api", "apnic", "apollo", "app", "apparatus", "apparel", "apparent", "apparently", "appeal", "appeals", "appear", "appearance", "appeared", "appearing", "appears", "appendix", "apple", "appliance", "appliances", "applicable", "applicant", "applicants", "application", "applications", "applied", "applies", "apply", "applying", "appointed", "appointment", "appointments", "appraisal", "appreciate", "appreciated", "appreciation", "approach", "approaches", "appropriate", "appropriations", "approval", "approve", "approved", "approx", "approximate", "approximately", "apps", "apr", "april", "apt", "aqua", "aquarium", "aquatic", "arab", "arabia", "arabic", "arbitrary", "arbitration", "arc", "arcade", "arch", "architect", "architects", "architectural", "architecture", "archive", "archived", "archives", "arctic", "are", "area", "areas", "arena", "arg", "argentina", "argue", "argued", "argument", "arguments", "arise", "arising", "arizona", "arkansas", "arlington", "arm", "armed", "armenia", "armor", "arms", "armstrong", "army", "arnold", "around", "arrange", "arranged", "arrangement", "arrangements", "array", "arrest", "arrested", "arrival", "arrivals", "arrive", "arrived", "arrives", "arrow", "art", "arthritis", "arthur", "article", "articles", "artificial", "artist", "artistic", "artists", "arts", "artwork", "aruba", "asbestos", "asia", "asian", "aside", "asin", "ask", "asked", "asking", "asks", "aspect", "aspects", "aspnet", "assault", "assembled", "assembly", "assess", "assessed", "assessing", "assessment", "assessments", "asset", "assets", "assign", "assigned", "assignment", "assignments", "assist", "assistance", "assistant", "assisted", "assists", "associate", "associated", "associates", "association", "associations", "assume", "assumed", "assumes", "assuming", "assumption", "assumptions", "assurance", "assure", "assured", "asthma", "astrology", "astronomy", "ate", "athens", "athletes", "athletic", "athletics", "atlanta", "atlantic", "atlas", "atmosphere", "atmospheric", "atom", "atomic", "attach", "attached", "attachment", "attachments", "attack", "attacked", "attacks", "attempt", "attempted", "attempting", "attempts", "attend", "attendance", "attended", "attending", "attention", "attitude", "attitudes", "attorney", "attorneys", "attract", "attraction", "attractions", "attractive", "attribute", "attributes", "auburn", "auckland", "auction", "auctions", "audi", "audience", "audio", "audit", "auditor", "august", "aurora", "austin", "australia", "australian", "austria", "authentic", "authentication", "author", "authorities", "authority", "authorization", "authorized", "authors", "auto", "automated", "automatic", "automatically", "automation", "automobile", "automobiles", "automotive", "autos", "autumn", "availability", "available", "avatar", "avenue", "average", "avg", "aviation", "avoid", "avoiding", "avon", "award", "awarded", "awards", "aware", "awareness", "away", "awesome", "awful", "axis", "aye", "azerbaijan", "babe", "babes", "babies", "baby", "bachelor", "back", "backed", "background", "backgrounds", "backing", "backup", "bacon", "bacteria", "bacterial", "bad", "badge", "badly", "bag", "baghdad", "bags", "bahamas", "bahrain", "bailey", "baker", "baking", "balance", "balanced", "bald", "bali", "ball", "ballet", "balloon", "ballot", "balls", "baltimore", "ban", "banana", "band", "bands", "bandwidth", "bang", "bangbus", "bangkok", "bangladesh", "bank", "banking", "bankruptcy", "banks", "banned", "banner", "banners", "baptist", "bar", "barbados", "barbara", "barbie", "barcelona", "bare", "barely", "bargain", "bargains", "barn", "barnes", "barrel", "barrier", "barriers", "barry", "bars", "base", "baseball", "based", "baseline", "basement", "basename", "bases", "basic", "basically", "basics", "basin", "basis", "basket", "basketball", "baskets", "bass", "bat", "batch", "bath", "bathroom", "bathrooms", "baths", "batman", "batteries", "battery", "battle", "battlefield", "bay", "beach", "beaches", "beads", "beam", "bean", "beans", "bear", "bearing", "bears", "beast", "beastality", "beastiality", "beat", "beatles", "beats", "beautiful", "beautifully", "beauty", "beaver", "became", "because", "become", "becomes", "becoming", "bed", "bedding", "bedford", "bedroom", "bedrooms", "beds", "bee", "beef", "been", "beer", "before", "began", "begin", "beginner", "beginners", "beginning", "begins", "begun", "behalf", "behavior", "behavioral", "behaviour", "behind", "beijing", "being", "beings", "belarus", "belfast", "belgium", "belief", "beliefs", "believe", "believed", "believes", "belize", "belkin", "bell", "belle", "belly", "belong", "belongs", "below", "belt", "belts", "ben", "bench", "benchmark", "bend", "beneath", "beneficial", "benefit", "benefits", "benjamin", "bennett", "benz", "berkeley", "berlin", "bermuda", "bernard", "berry", "beside", "besides", "best", "bestiality", "bestsellers", "bet", "beta", "beth", "better", "betting", "betty", "between", "beverage", "beverages", "beverly", "beyond", "bg", "bhutan", "bi", "bias", "bible", "biblical", "bibliographic", "bibliography", "bicycle", "bid", "bidder", "bidding", "bids", "big", "bigger", "biggest", "bike", "bikes", "bikini", "bill", "billing", "billion", "bills", "billy", "bin", "binary", "bind", "binding", "bingo", "bio", "biodiversity", "biographies", "biography", "biol", "biological", "biology", "bios", "biotechnology", "bird", "birds", "birmingham", "birth", "birthday", "bishop", "bit", "bite", "bits", "biz", "bizarre", "bizrate", "bk", "bl", "black", "blackberry", "blackjack", "blacks", "blade", "blades", "blah", "blair", "blake", "blame", "blank", "blanket", "blast", "bleeding", "blend", "bless", "blessed", "blind", "blink", "block", "blocked", "blocking", "blocks", "blog", "blogger", "bloggers", "blogging", "blogs", "blond", "blonde", "blood", "bloody", "bloom", "bloomberg", "blow", "blowing", "blue", "blues", "bluetooth", "blvd", "bmw", "board", "boards", "boat", "boating", "boats", "bob", "bobby", "boc", "bodies", "body", "bold", "bolivia", "bolt", "bomb", "bon", "bond", "bonds", "bone", "bones", "bonus", "book", "booking", "bookings", "bookmark", "bookmarks", "books", "bookstore", "bool", "boolean", "boom", "boost", "boot", "booth", "boots", "border", "borders", "bored", "boring", "born", "borough", "bosnia", "boss", "boston", "both", "bother", "botswana", "bottle", "bottles", "bottom" };
char generatedLetters[17]; // global array to store 16 random letters + null terminator

// Function prototypes
int readPushButtons();
void clearEdgeCapture();
int waitForKeyPressAndRelease();
void playGame();
void handleKeyboardInput(char *word);
void generateRandomLetters();
bool isValidWord(const char *word);
bool isLetterInGenerated(const char *word);
void findAndPrintWords();
bool canFormWordWithGeneratedLetters(const char *word);

int main() {
    srand(time(NULL)); // Seed the random number generator
	//rand()

    printf("Welcome to the Boggle Game!\n");
    printf("Press key0 for Easy level, key1 for Medium level, key2 for Hard level.\n");

    while (true) {
        int key = waitForKeyPressAndRelease(); // Wait for a key press and release

        if (key == 0) { // Easy level
            printf("Starting Easy level.\n");
            generateRandomLetters(4); // Generate 4 random letters
			findAndPrintWords();
            playGame();
        } else if (key == 1) { // Medium level
            printf("Starting Medium level.\n");
            generateRandomLetters(9); // Generate 9 random letters
            playGame();
        } else if (key == 2) { // Hard level
            printf("Starting Hard level.\n");
            generateRandomLetters(16); // Generate 16 random letters
            playGame();
        }
    }
    return 0;
}

// Function to read the state of the pushbuttons (keys)
int readPushButtons() {
    volatile int *pushButtons = (int *)0xFF200050; // Address for pushbutton keys
    return *pushButtons & 0x7; // Read the state of the pushbuttons
}

// Function to clear the edge capture register
void clearEdgeCapture() {
    volatile int *KEYs = (int *)0xFF200050; // pushbutton base address
    *(KEYs + 3) = 0x7; // Clear edge capture register by writing back the same value
}

// Function to wait for a key press and release
int waitForKeyPressAndRelease() {
    volatile int *KEYs = (int *)0xFF200050; // pushbutton base address
    int edge_cap;
    
    // Wait for an edge (press and release) to be captured
    while (true) {
        edge_cap = *(KEYs + 3); // Read the edge capture register
        
        if (edge_cap & 0x1) {
            clearEdgeCapture(); // Clear the edge capture register for KEY0
            return 0; // Key 0 pressed and released
        } else if (edge_cap & 0x2) {
            clearEdgeCapture(); // Clear the edge capture register for KEY1
            return 1; // Key 1 pressed and released
        } else if (edge_cap & 0x4) {
            clearEdgeCapture(); // Clear the edge capture register for KEY2
            return 2; // Key 2 pressed and released
        }
    }
}

// Random Letter Generator
void generateRandomLetters(int level) {
    int numberOfLetters = level; // Use level to determine the number of letters
	
	/* Since its not working rn
    for (int i = 0; i < numberOfLetters; ++i) { 
        generatedLetters[i] = 'A' + (rand() % 26); // Generate random uppercase letter
    }
    generatedLetters[numberOfLetters] = '\0'; // Null-terminate the string
	*/
	
	// constant array for now
    memset(generatedLetters, 0, sizeof(generatedLetters));

    if (numberOfLetters == 4) {
        char letters[] = {'A', 'B', 'C', 'D'};
        for (int i = 0; i < numberOfLetters; ++i) {
            generatedLetters[i] = letters[i];
        }
    } else if (numberOfLetters == 9) {
        char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
        for (int i = 0; i < numberOfLetters; ++i) {
            generatedLetters[i] = letters[i];
        }
    } else if (numberOfLetters == 16) {
        char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'O', 'P', 'Q'};
        for (int i = 0; i < numberOfLetters; ++i) {
            generatedLetters[i] = letters[i];
        }
    }

	generatedLetters[numberOfLetters] = '\0';
    printf("Generated Letters: %s\n", generatedLetters);
}

bool isLetterInGenerated(const char *word) {
    for (int i = 0; word[i] != '\0'; ++i) {
        if (!strchr(generatedLetters, word[i])) { //////
            return false; // Letter not found in generatedLetters
        }
    }
    return true; // All letters found
}

bool isValidWord(const char *word) {
    int wordCount = sizeof(englishwords) / sizeof(englishwords[0]);
    for (int i = 0; i < wordCount; ++i) {
        if (strcmp(englishwords[i], word) == 0) {
            return true; // Word found in the list
        }
    }
    return false; // Word not found
}

void playGame() {
    char input[50]; // Assuming maximum word length is 50 characters
    char enteredWords[100][50]; // Array to store up to 100 entered valid words
    int enteredCount = 0; // Count of valid words entered

    while (true) {
        printf("Enter a word (or type EXIT to finish): ");
        handleKeyboardInput(input);

        if (strcmp(input, "EXIT") == 0) {
            printf("Exiting to level selection.\n");
            break;
        }

        if (!isLetterInGenerated(input)) {
            printf("Error: The word '%s' contains letters not in the grid.\n", input);
            continue;
        }

        if (!isValidWord(input)) {
            printf("Error: '%s' is not a valid word.\n", input);
            continue;
        }

        bool wordAlreadyEntered = false;
        for (int i = 0; i < enteredCount; ++i) {
            if (strcmp(enteredWords[i], input) == 0) {
                wordAlreadyEntered = true;
                printf("Error: '%s' has already been entered.\n", input);
                break;
            }
        }

        if (!wordAlreadyEntered) {
            strcpy(enteredWords[enteredCount++], input); // Add the valid word to the list of entered words
            printf("'%s' is a valid word!\n", input);
        }
    }
}

// Function to handle keyboard input and add letters to the array
void handleKeyboardInput(char *word) {
    int keyData;
    bool enterPressed = false;
    int wordIndex = 0;
    bool keyReleased = false; // Track if the last key was released
    char letter;

    while (!enterPressed) { // While "ENTER" has not been pressed
        keyData = *ps2_ptr; // keyData contains the scan code of the key address
        if (keyData != 0) { // Check if the key has data, meaning it has been pressed
            int key = keyData & 0xFF; // Extract the lower 8 bits

            if (key == 0xF0) { // Key release code
                keyReleased = true;
            } else if (keyReleased) {
                // Map the key press to a character, default to '\0' if not a letter
                letter = '\0';
                switch (key) {
                    case 0x1C: word[wordIndex++] = 'A'; printf("Letter A added\n"); break;
                    case 0x32: word[wordIndex++] = 'B'; printf("Letter B added\n"); break;
                    case 0x21: word[wordIndex++] = 'C'; printf("Letter C added\n"); break;
                    case 0x23: word[wordIndex++] = 'D'; printf("Letter D added\n"); break;
                    case 0x24: word[wordIndex++] = 'E'; printf("Letter E added\n"); break;
                    case 0x2B: word[wordIndex++] = 'F'; printf("Letter F added\n"); break;
                    case 0x34: word[wordIndex++] = 'G'; printf("Letter G added\n"); break;
                    case 0x33: word[wordIndex++] = 'H'; printf("Letter H added\n"); break;
                    case 0x43: word[wordIndex++] = 'I'; printf("Letter I added\n"); break;
                    case 0x3B: word[wordIndex++] = 'J'; printf("Letter J added\n"); break;
                    case 0x42: word[wordIndex++] = 'K'; printf("Letter K added\n"); break;
                    case 0x4B: word[wordIndex++] = 'L'; printf("Letter L added\n"); break;
                    case 0x3A: word[wordIndex++] = 'M'; printf("Letter M added\n"); break;
                    case 0x31: word[wordIndex++] = 'N'; printf("Letter N added\n"); break;
                    case 0x44: word[wordIndex++] = 'O'; printf("Letter O added\n"); break;
                    case 0x4D: word[wordIndex++] = 'P'; printf("Letter P added\n"); break;
                    case 0x15: word[wordIndex++] = 'Q'; printf("Letter Q added\n"); break;
                    case 0x2D: word[wordIndex++] = 'R'; printf("Letter R added\n"); break;
                    case 0x1B: word[wordIndex++] = 'S'; printf("Letter S added\n"); break;
                    case 0x2C: word[wordIndex++] = 'T'; printf("Letter T added\n"); break;
                    case 0x3C: word[wordIndex++] = 'U'; printf("Letter U added\n"); break;
                    case 0x2A: word[wordIndex++] = 'V'; printf("Letter V added\n"); break;
                    case 0x1D: word[wordIndex++] = 'W'; printf("Letter W added\n"); break;
                    case 0x22: word[wordIndex++] = 'X'; printf("Letter X added\n"); break;
                    case 0x35: word[wordIndex++] = 'Y'; printf("Letter Y added\n"); break;
                    case 0x1A: word[wordIndex++] = 'Z'; printf("Letter Z added\n"); break;
                    case 0x5A: enterPressed = true; break; // Enter key pressed
                }

                // Check if letter is in the generatedLetters array before appending
                if (strchr(generatedLetters, letter) != NULL || letter == '\0') {
                    if (!enterPressed && letter != '\0') { // Append if it's a valid letter and not the ENTER key
                        word[wordIndex++] = letter;
                    }
                } else {
                    // Optionally, inform the user that the entered letter is not valid
                    printf("Entered letter '%c' is not in the generated letters.\n", letter);
                }

                keyReleased = false; // Reset for next key press
            }
        }
    }

    word[wordIndex] = '\0'; // End of String
}

void findAndPrintWords() {
    printf("Words that can be formed:\n");
    int wordCount = sizeof(englishwords) / sizeof(englishwords[0]);
    for (int i = 0; i < wordCount; ++i) {
        if (canFormWordWithGeneratedLetters(englishwords[i])) {
            printf("%s\n", englishwords[i]);
        }
    }
}

// Helper function to determine if a word can be formed with the generated letters
bool canFormWordWithGeneratedLetters(const char *word) {
    char tempLetters[17]; // Temporary copy of generatedLetters to mark used letters
    strcpy(tempLetters, generatedLetters);
    
    for (int i = 0; word[i] != '\0'; ++i) {
        char *found = strchr(tempLetters, word[i]);
        if (!found) {
            return false; // Letter not found in generatedLetters, or already used
        } else {
            *found = '0'; // Mark this letter as used by replacing it with '0'
        }
    }
    return true; // All letters of the word were found in generatedLetters
}
