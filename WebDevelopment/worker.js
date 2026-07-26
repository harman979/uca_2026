self.onmessage = function (e) {
    const users = e.data;

    if (!users || users.length === 0) {
        self.postMessage({ error: "No users returned from API" });
        return;
    }

    const result = users.map(user => ({
        name: user.name,
        status: user.active ? "Active" : "Inactive"
    }));

    self.postMessage(result);
};
