const worker = new Worker("worker.js");

async function fetchUsers() {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const users = await response.json();

        worker.postMessage(users);
    } catch (error) {
        console.error(error.message);
    }
}

worker.onmessage = function (e) {
    if (e.data.error) {
        console.error(e.data.error);
        return;
    }

    e.data.forEach(user => {
        console.log(`${user.name} - ${user.status}`);
    });
};

fetchUsers();
