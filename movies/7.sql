Select m.title, r.rating from movies m
join ratings r on m.id = r.movie_id
where m. year = 2010
order by r.rating DESC, m.title ASC;