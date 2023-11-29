destination(mumbai, asia, culture, beach, summer).
destination(paris, europe, culture, moderate, spring).
destination(tokyo, asia, culture, expensive, spring).
destination(new_york, north_america, shopping, expensive, autumn).
destination(dubai, middle_east, luxury, expensive, winter).
destination(bangkok, asia, beach, moderate, summer).
destination(rio_de_janeiro, south_america, beach, moderate, summer).
destination(london, europe, culture, moderate, summer).
destination(rome, europe, culture, moderate, spring).
destination(sydney, australia, beach, expensive, summer).
destination(amsterdam, europe, culture, moderate, spring).
destination(hong_kong, asia, shopping, expensive, autumn).
destination(cancun, north_america, beach, moderate, summer).
destination(cairo, africa, culture, cheap, spring).
destination(cape_town, africa, beach, moderate, summer).
destination(mexico_city, north_america, culture, cheap, autumn).
destination(moscow, europe, culture, moderate, winter).
destination(athens, europe, culture, moderate, summer).
destination(istanbul, europe, culture, moderate, spring).
destination(mumbai, asia, culture, cheap, winter).
destination(seoul, asia, culture, moderate, autumn).
destination(bali, asia, beach, moderate, summer).

recommend(Destination, Budget, Interest, Weather) :-
    destination(Destination, _, Interest, Budget, Weather).

start :- 
    write('Welcome to Travel Planner'), nl,
    ask_budget(Budget),
    ask_interest(Interest),
    ask_weather(Weather),
    findall(Destination, recommend(Destination, Budget, Interest, Weather), Destinations),
    display(Destinations).

ask_budget(Budget):-
    write("what is ur budget"), nl,
    read(Budget).

ask_interest(Interest):-
    write("what is ur interest"), nl,
    read(Interest).

ask_weather(Weather):-
    write("what is ur preferred weather"), nl,
    read(Weather).

display([]):-
    write("No recommendations"), nl.

display(Destinations) :- 
    write("Recommendations:"), nl,
    display_list(Destinations).

display_list([]).
    display_list([H|T]):-
    write(' - '), write(H), nl, display_list(T).