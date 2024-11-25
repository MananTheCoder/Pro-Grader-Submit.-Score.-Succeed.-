import requests
from datetime import datetime

def get_submission_calendar(username):
    url = "https://leetcode.com/graphql"
    
    # GraphQL query to fetch user submission calendar
    query = """
    query getUserProfile($username: String!) {
      matchedUser(username: $username) {
        submissionCalendar
      }
    }
    """

    variables = {
        "username": username
    }

    response = requests.post(url, json={"query": query, "variables": variables})
    
    if response.status_code == 200:
        data = response.json()
        calendar_data = data['data']['matchedUser']['submissionCalendar']
        return calendar_data
    else:
        print(f"Failed to fetch data: {response.status_code}")
        return {}

def filter_submissions_by_date(submission_calendar, start_date, end_date):
    start_date = datetime.strptime(start_date, "%Y-%m-%d")
    end_date = datetime.strptime(end_date, "%Y-%m-%d")
    
    solved_in_range = 0
    
    # Convert the submission calendar (which is a JSON string) to a dictionary
    submission_data = eval(submission_calendar)
    
    for timestamp_str, count in submission_data.items():
        submission_date = datetime.fromtimestamp(int(timestamp_str))
        if start_date <= submission_date <= end_date:
            solved_in_range += count
    
    return solved_in_range

# Example usage:
username = "darshanpadia5"
submission_calendar = get_submission_calendar(username)

start_date = "2024-08-01"
end_date = "2024-10-21"

solved_count = filter_submissions_by_date(submission_calendar, start_date, end_date)
print(f"Number of problems solved by {username} between {start_date} and {end_date}: {solved_count}")
