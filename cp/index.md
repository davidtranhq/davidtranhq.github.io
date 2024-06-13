---
layout: default
permalink: /cp/
---

Solutions to competitive programming problems that includes the thought process toward the solution.

Tips for solving:
1. Find the appropriate level of abstraction for the problem. At the most abstract, consider only the definitions at play. At the most concrete, consider specific examples. But this is a specturm, so consider everything in between.
2. Think at a complexity proportional to the complexity of the structure at play.
3. To reduce redundant computation, note that the information from the computation done is stored in the results. If not enough information is available, store more results. If there is enough, leverage the results.

{% for page in site.pages %}
{% if page.folder == 'cp' %}
- [{{ page.title }}]({{ page.url }})
{% endif %}
{% endfor %}