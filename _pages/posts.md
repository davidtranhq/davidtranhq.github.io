---
layout: default
permalink: "/posts/"
title: Posts
---

{% if site.paginate %}
{% assign posts = paginator.posts %}
{% else %}
{% assign posts = site.posts %}
{% endif %}


{%- if posts.size > 0 -%}
{%- if page.list_title -%}
<h2 class="post-list-heading">{{ page.list_title }}</h2>
{%- endif -%}
<ul class="post-list">
    {%- assign date_format = site.minima.date_format | default: "%b %-d, %Y" -%}
    {%- for post in posts -%}
    <li>
        <a class="post-link" href="{{ post.url | relative_url }}">
            {{ post.title | escape }}
        </a>
        <span class="post-meta">{{ post.date | date: date_format }}</span>
        {%- if site.show_excerpts -%}
        {{ post.excerpt }}
        <a class="post-more" href="{{ post.url | relative_url }}">
            Read more...
        </a>
        {%- endif -%}
    </li>
    {%- endfor -%}
</ul>

{% if site.paginate %}
<div class="pager">
    <ul class="pagination">
        {%- if paginator.previous_page %}
        <li><a href="{{ paginator.previous_page_path | relative_url }}" class="previous-page">{{
                paginator.previous_page }}</a></li>
        {%- else %}
        <li>
            <div class="pager-edge">•</div>
        </li>
        {%- endif %}
        <li>
            <div class="current-page">{{ paginator.page }}</div>
        </li>
        {%- if paginator.next_page %}
        <li><a href="{{ paginator.next_page_path | relative_url }}" class="next-page">{{ paginator.next_page }}</a>
        </li>
        {%- else %}
        <li>
            <div class="pager-edge">•</div>
        </li>
        {%- endif %}
    </ul>
</div>
{%- endif %}

{%- endif -%}