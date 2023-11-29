SELECT DISTINCT p.name
FROM people AS p
JOIN stars AS s ON p.id = s.person_id
JOIN movies AS m ON s.movie_id = m.id
JOIN stars AS kb_s ON m.id = kb_s.movie_id
JOIN people AS kb_p ON kb_s.person_id = kb_p.id
WHERE kb_p.name = 'Kevin Bacon'
AND kb_p.birth = 1958
AND p.name != 'Kevin Bacon';
