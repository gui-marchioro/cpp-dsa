import requests
import sys
from markdownify import markdownify as md


def fetch_leetcode_description(slug: str) -> dict:
    url = "https://leetcode.com/graphql"

    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId
        title
        content
        difficulty
        topicTags {
          name
        }
      }
    }
    """

    variables = {"titleSlug": slug}

    response = requests.post(
        url,
        json={"query": query, "variables": variables},
        headers={
            "Content-Type": "application/json",
            "Referer": f"https://leetcode.com/problems/{slug}/"
        }
    )

    if response.status_code != 200:
        raise Exception(f"Failed to fetch data: {response.status_code}")

    data = response.json()

    if "errors" in data:
        raise Exception(f"Error from LeetCode API: {data['errors']}")

    return data["data"]["question"]


def convert_to_markdown(question_data: dict) -> str:
    qid = question_data["questionFrontendId"]
    title = question_data["title"]
    difficulty = question_data["difficulty"]
    tags = [tag["name"] for tag in question_data["topicTags"]]
    content_html = question_data["content"]

    content_md = md(content_html)

    md_text = f"# {qid}. {title}\n\n"
    md_text += f"**Difficulty:** {difficulty}\n\n"
    md_text += f"**Tags:** {', '.join(tags)}\n\n"
    md_text += "---\n\n"
    md_text += content_md

    return md_text


def save_markdown(slug: str, markdown_text: str):
    filename = f"{slug}.md"
    with open(filename, "w", encoding="utf-8") as f:
        f.write(markdown_text)
    print(f"Saved to {filename}")


def main():
    if len(sys.argv) != 2:
        print("Usage: python script.py <problem-slug>")
        sys.exit(1)

    slug = sys.argv[1]

    try:
        question_data = fetch_leetcode_description(slug)
        markdown_text = convert_to_markdown(question_data)
        save_markdown(slug, markdown_text)
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()