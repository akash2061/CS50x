SELECT avg(energy) FROM songs
where artist_id = (select id from artists where name = "Drake");