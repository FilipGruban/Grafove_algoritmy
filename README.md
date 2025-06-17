# Grafove_algoritmy

1. Úvod do grafů
1.1 Definice grafu

Graf je matematická struktura, která se skládá z množiny vrcholů (uzlů) a množiny hran (spojení mezi vrcholy).

    Orientovaný graf – hrany mají směr (např. A → B znamená hranu z A do B).

    Neorientovaný graf – hrany nemají směr (např. spojení A — B je obousměrné).

    Ohodnocený graf – každá hrana má přiřazenou váhu (např. vzdálenost, čas, náklady).

1.2 Kostra grafu

Kostra grafu je podgraf obsahující všechny vrcholy původního grafu a co nejméně hran tak, aby byl graf souvislý (spojuje všechny uzly). Typicky se řeší v kontextu minimalizace nákladů (např. minimální kostra — MST, např. Kruskalův nebo Primův algoritmus).
1.3 Matice sousednosti vs. seznam sousedů

    Matice sousednosti: čtvercová matice velikosti V x V, kde prvek na pozici (i, j) obsahuje váhu hrany mezi vrcholy i a j. Pokud hrana neexistuje, často je zde ∞ nebo 0.

    Seznam sousedů: každý vrchol má přiřazený seznam všech vrcholů, do kterých vede hrana, často i s váhou.

1.4 Reálné příklady využití grafů

    Navigace a plánování tras (Google Maps, GPS navigace)

    Počítačové sítě a internet

    Logistika a plánování dopravy

    Sociální sítě a jejich propojení

    Analýza závislostí (např. projektové řízení)

2. Problém hledání nejkratší cesty
2.1 Co znamená „nejkratší cesta“

Nejkratší cesta mezi dvěma vrcholy je taková posloupnost hran, že součet jejich váh je minimální.

Např.: Cesta A → B → D s délkou 10 je kratší než A → C → E → D s délkou 12, pokud váhy hran tomu odpovídají.
2.2 Negativní hrany a jejich vliv

    Pokud graf obsahuje záporné hrany (váha hrany je záporné číslo), některé algoritmy (např. Dijkstra) nefungují správně.

    Pokud navíc existují záporné cykly (lze obcházet cyklus a snižovat vzdálenost stále níže), většina algoritmů není schopná najít řešení.

3. Přehled algoritmů
3.a Dijkstrův algoritmus

    Princip: greedy přístup, vybírá vždy vrchol s aktuálně nejnižší známou vzdáleností, používá prioritní frontu.

    Omezení: nefunguje správně při výskytu záporných hran.

    Časová složitost:

        O(V²) pro jednoduchou implementaci.

        O((V + E) log V) při použití prioritní fronty (např. s haldou).

3.b Bellman-Fordův algoritmus

    Princip: opakuje relaxaci všech hran až V−1 krát.

    Výhoda: funguje i s negativními hranami.

    Detekce záporných cyklů: lze jednoduše detekovat při poslední iteraci.

    Časová složitost: O(V × E)

3.c Floyd-Warshallův algoritmus

    Princip: dynamické programování — pro každou dvojici vrcholů zkouší, zda není výhodnější jít přes třetí mezivrchol.

    Vhodný pro: výpočet všech nejkratších cest mezi všemi dvojicemi vrcholů.

    Časová složitost: O(V³)
    
4. Závěr

V projektu byly studovány různé algoritmy pro hledání nejkratší cesty v grafech. Každý má své výhody podle typu problému. Floyd-Warshallův algoritmus byl úspěšně implementován a použit pro nalezení nejkratších cest mezi všemi dvojicemi vrcholů v zadaném grafu.
4.1 Možnosti rozšíření:

    A algoritmus* — vhodný pro heuristické hledání cest (např. v herní AI, navigaci).

    Johnsonův algoritmus — vhodný pro všechny-páry v grafu s negativními hranami (ale bez záporných cyklů), efektivnější než Floyd-Warshall pro řídké grafy.

